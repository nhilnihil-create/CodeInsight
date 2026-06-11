#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> X, Y, Xsum, Ysum;
int dpx[4000][17000], dpy[4000][17000];
int main() {
	string s;
	int x, y;
	cin >> s >> x >> y;
	int which=1, cnt=0;
	bool head=true;
	for(int i=0; i<s.size(); ++i){
	    if(s[i]=='T'){
	        if(head){
	            x -= cnt;
	            head=false;
	        }
	        else if(cnt>0){
	            if(which>0){
	                x += cnt;
	                X.push_back(cnt);
	                if(Xsum.size()>0) Xsum.push_back(Xsum.back()+cnt);
	                else Xsum.push_back(cnt);
	            }else{
	                y += cnt;
	                Y.push_back(cnt);
	                if(Ysum.size()>0) Ysum.push_back(Ysum.back()+cnt);
	                else Ysum.push_back(cnt);
	            }
	        }
	        which=1-which;
	        cnt=0;
	    }
	    else ++cnt;
	}
	if(cnt>0){
	    if(head) x -= cnt;
	    else if(which>0){
	        x += cnt;
	        X.push_back(cnt);
	        if(Xsum.size()>0) Xsum.push_back(Xsum.back()+cnt);
	        else Xsum.push_back(cnt);
	        
	    }else{
	        y += cnt;
	        Y.push_back(cnt);
	        if(Ysum.size()>0) Ysum.push_back(Ysum.back()+cnt);
	        else Ysum.push_back(cnt);
	    }
	}
	bool flag;
	if(x<0 || x%2>0 || y<0 || y%2>0) flag=false;
	else{
	    dpx[0][0]=1, dpy[0][0]=1;
	    for(int i=0; i<X.size(); ++i){
	        for(int j=0; j<=Xsum[i]; ++j){
	            dpx[i+1][j]=dpx[i][j];
	            if(X[i]<=j){
	                if(dpx[i][j-X[i]]==1) dpx[i+1][j]=1;
	            }
	        }
	    }
	    for(int i=0; i<Y.size(); ++i){
	        for(int j=0; j<=Ysum[i]; ++j){
	            dpy[i+1][j]=dpy[i][j];
	            if(Y[i]<=j){
	                if(dpy[i][j-Y[i]]==1) dpy[i+1][j]=1;
	            }
	        }
	    }
	    flag=(dpx[X.size()][x/2]==1) && (dpy[Y.size()][y/2]==1);
	}
	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}

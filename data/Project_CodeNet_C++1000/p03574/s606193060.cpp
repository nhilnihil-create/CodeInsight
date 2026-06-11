#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main(){
	int h,w; cin>>h>>w;
	vector<vector<char>> v(h,vector<char>(w));
	rep(i,h){
		string s; cin>>s;
		rep(j,w){
			v[i][j]=s[j];
		}
	}
	vector<vector<string>> a(h,vector<string>(w,"#"));
	rep(i,h){
		rep(j,w){
			int cnt=0;
			for(int k=-1; k<=1; k++){
				for(int l=-1; l<=1; l++){
					if(i+k<0||j+l<0||i+k>=h||j+l>=w) continue;
					else if(k==0&&l==0) continue;
					else if(v[i+k][j+l]=='#') cnt++;
				}
			}
          if(v[i][j]=='#') continue;
		else a[i][j]=to_string(cnt);
		}
	}
  rep(i,h){
    rep(j,w){
      cout<<a[i][j];
    }
    cout<<endl;
  }

}
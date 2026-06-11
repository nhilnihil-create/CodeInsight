#include <bits/stdc++.h>
using namespace std;
#define int long long
    



signed main(){
    int x,y;
    string s;
    cin >> s>>x>>y;
    vector<int> w0,w1;
    int p=0,q=0;
    int i0=0;
    while(i0<s.length()&&s[i0]=='F'){
        i0++;
        p++;
    }
    w0.push_back(abs(x-p));
    w1.push_back(abs(y));
    int maxs=max(abs(x-p),abs(y));
    q=1;p=0;
    
    for(int i=i0+1;i<s.length();i++){
        if(s[i]=='F')p++;
        else{
            if(p!=0){
                if(q==0)w0.push_back(p);
                else w1.push_back(p);
                
                maxs=max(maxs,p);
            }
            p=0;
            q=  !q;
        }
    }
    if(q==0)w0.push_back(p);
    else w1.push_back(p);
                
    maxs=max(maxs,p);
    int k1[w0.size()][2*maxs+1];
    for(int i=0;i<w0.size();i++){
        for(int j=0;j<2*maxs+1;j++)k1[i][j]=0;
    }
    k1[0][maxs+w0[0]]=1;k1[0][maxs-w0[0]]=1;
    for(int i=1;i<w0.size();i++){
        for(int j=0;j<2*maxs+1-w0[i];j++){
            k1[i][j]=k1[i-1][j+w0[i]];
        }
        for(int j=0;j<2*maxs+1-w0[i];j++){
            k1[i][j+w0[i]]+=k1[i-1][j];
        }
    }
    int k2[w1.size()][2*maxs+1];
    for(int i=0;i<w1.size();i++){
        for(int j=0;j<2*maxs+1;j++)k2[i][j]=0;
    }
    k2[0][maxs+w1[0]]=1;k2[0][maxs-w1[0]]=1;
    for(int i=1;i<w1.size();i++){
        for(int j=0;j<2*maxs+1-w1[i];j++){
            k2[i][j]=k2[i-1][j+w1[i]];
        }
        for(int j=0;j<2*maxs+1-w1[i];j++){
            k2[i][j+w1[i]]+=k2[i-1][j];
        }
    }
    if(k1[w0.size()-1][maxs]!=0&&k2[w1.size()-1][maxs]!=0)cout << " Yes ";
    else cout << " No ";
   // cerr << maxs << endl;
    //for(int i=0;i<2*maxs+1;i++){
    //    cerr << w0[0]<<' ';
  //      cerr << k1[0][i]<<' ';
    //}

    return 0;
}
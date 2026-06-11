#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
int main(){
    string s;
    cin>>s;
    int n = s.length();
    int k;
    cin>>k;
    char min = 'z';
    char smin = 'z';
    vector<int> p;
    vector<int> sp;
    map<string,int> po;
    vector<string> T;
    if(n<=100){
    for(int i=0;i<n;i++){
        for(int j=1;j<=n-i;j++){
        string t = s.substr(i,j);
        po[t]++;
        if(po[t]==1){
            T.push_back(t);
        }
        //cout<<t<<endl;
        }
    }
    all(T);
    cout<<T[k-1]<<endl;
    }
    else{
    rep(i,n){
        if(s[i]<min){
            smin = min;
            min = s[i];
        }
    }
    //cout<<min<<endl;
    rep(i,n){
        if(s[i]==min){
            p.push_back(i);
        }
        if(s[i]==smin){
            sp.push_back(i);
        }
    }
    for(int i=0;i<p.size();i++){
        for(int j=1;j<=5;j++){
            if(p[i]+j>n)break;
            string t = s.substr(p[i],j);
            po[t]++;
            if(po[t]==1){
                T.push_back(t);
            }
        }
    }
    for(int i=0;i<sp.size();i++){
        for(int j=1;j<=5;j++){
            if(sp[i]+j>n)break;
            string t = s.substr(sp[i],j);
            po[t]++;
            if(po[t]==1){
                T.push_back(t);
            }
        }
    }
    all(T);
    cout<<T[k-1]<<endl;
    }
}
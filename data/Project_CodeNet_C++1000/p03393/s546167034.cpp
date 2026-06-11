#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
bool tasai(string s,int l){
    //int l = s.length();
    //cout<<l<<endl;
    map<char,int> p;
    rep(i,l){
        p[s[i]]++;
        if(p[s[i]]>=2){
            return false;
        }
    }
    return true;
}
int main(){
    string s;
    cin>>s;
    if(s=="zyxwvutsrqponmlkjihgfedcba"){
        cout<<-1<<endl;
        return 0;
    }
    int n=s.length();
    map<char,int> p;
    rep(i,n){
        //s[i] = s[i]+1; これでabcd順に進められる
        p[s[i]]++;
    }
    if(n<=25){
    rep(i,26){
        if(p['a'+i]==0){
            s[n] = 'a'+i;
            //cout<<s[n]<<endl;
            break;
        }
    }
    cout<<s+s[n]<<endl;
    }
    else{
        int j=0;
        s[n-1]=s[n-1]+1;
        while(1){
            bool Tasai=false;
            for(int i=0;i<=26;i++){
                if(i>=1){
                s[n-1-j] = s[n-1-j]+1;
                }
                if(s[n-1-j]>'z'){
                    s[n-1-j]='\0';
                   // cout<<"next"<<endl;
                    break;
                }
                if(tasai(s,26-j)){
                    Tasai = true;
                   // cout<<"GET"<<endl;
                    break;
                }
                //cout<<s<<endl;
            }
            if(Tasai){
                break;
            }
            j++;
            //cout<<s<<endl;
            s[n-1-j] = s[n-1-j]+1;
        }
        rep(i,26-j){
        cout<<s[i];
        }
        cout<<endl;
    }
}
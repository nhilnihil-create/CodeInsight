#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int in() {int x; cin>>x; return x;}
ll lin() {ll x; cin>>x; return x;}
string sin() {string x;cin>>x;return x;}
using graph = vector<vector<int>>;
using graph2 = vector<vector<pair<int, int>>>;

int main(){
    string s;
    cin>>s;
    char a;
    if(s.size()<26){
        rep(i, 26){
            a='a'+i;
            if(s.find(a)==-1){
                break;
            }
        }
        cout<<s+a<<endl;
    }
    else{
        if(s=="zyxwvutsrqponmlkjihgfedcba"){
            cout<<-1<<endl;
        }
        else{
            int b[26];
            rep(i, 26){
                b[i]=s.at(i)-'a';
            }
            next_permutation(b, b+26);
            string t="aaaaaaaaaaaaaaaaaaaaaaaaaa";
            rep(i, 26){
                t.at(i)=b[i]+'a';
            }
            int j=0;
            rep(i, 26){
                if(s.at(i)!=t.at(i)){
                    j=i;
                    break;
                }
            }
            rep(i, j+1){
                cout<<t.at(i);
            }
            cout<<endl;
        }
    }
}
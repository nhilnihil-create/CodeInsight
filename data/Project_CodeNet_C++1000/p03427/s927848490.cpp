#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define bigger (char)toupper
#define smaller (char)tolower
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    string S;
    cin>>S;
    if(S.size()==1) {
        cout<<S<<endl;
    }
    else {
        int counter=0;
        bool ok=true;
        for(int i=1; i<S.size(); i++) {
            if(S[i]!='9') ok=false;
        }
        if(ok) {
            counter+=(S.size()-1)*9;
            counter+=S[0]-'0';
        }
        else {
            counter+=(S.size()-1)*9;
            counter+=S[0]-'1';
        }
        cout<<counter<<endl;
    }
}
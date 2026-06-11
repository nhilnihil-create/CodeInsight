#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define cout(x) cout<<x<<endl
#define all(v) v.begin(), v.end()
using namespace std;
//型エイリアス
using vi = vector<int>;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
const ll inf = 1e18;
const int N = 2e5 + 10;

int main(){
    string s;
    cin >> s;
    
    int a = (int)s[0] - '0';
    int b = (int)s[1] - '0';
    int c = (int)s[2] - '0';
    int d = (int)s[3] - '0';

    for(int i=0; i<(1<<3); ++i){
        int sum = a;
        bitset<3> t = i;
        if(t[2]==1) sum += b;
        else sum -= b; 
        if(t[1]==1) sum +=   c;
        else sum -=  c; 
        if(t[0]==1) sum +=   d;
        else sum -=  d; 

        if(sum==7){
            string u;
            u = (char)(a + '0');
            if(t[2]==1) u += '+';
            else u += '-';
            u += (char)(b + '0');
            if(t[1]==1) u += '+';
            else u += '-';
            u += (char)(c + '0');
            if(t[0]==1) u += '+';
            else u += '-';
            u += (char)(d + '0');
            u += "=7";
            cout(u); 
            break;
        }
    }



    return 0;

}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;
//stoi(s) : string→int stoll(s) :string→longlong  int→string to_string(i)
const double PI = acos(-1.0);
//小数点の表し方 cout << fixed << setprecision(5);

int main(){
    string s,t;
    cin >> s >> t;
    int n = s.size();
    vector<int> as(n),at(n);
    map<char,int> ms,mt;
    ms[s[0]] = 1;
    mt[t[0]] = 1;
    as[0] = 1;
    at[0] = 1;
    for(int i=0;i<n;i++){
        if(ms[s[i]] == 0){
            ms[s[i]] = ms.size();
            as[i] = ms[s[i]];
        }else{
            as[i] = ms[s[i]];
        }
    }
    for(int i=0;i<n;i++){
        if(mt[t[i]] == 0){
            mt[t[i]] = mt.size();
            at[i] = mt[t[i]];
        }else{
            at[i] = mt[t[i]];
        }
    }
    /*
    for(int i=0;i<n;i++){
        cout << as[i] << endl;
    }
    */
   for(int i=0;i<n;i++){
       if(at[i] != as[i]){
           cout << "No" << endl;
           return 0;
       }
   }
   cout << "Yes" << endl;
}
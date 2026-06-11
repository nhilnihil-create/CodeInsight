#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <sstream>
#include <numeric>
#include <cctype>
#include <bitset>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define SIZE 100005
#define INF 1000000000000000LL
using pint = pair<int,int>;
using vec = vector<int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main() {
    string s;
    cin>>s;
    int AA,BB;
    if(s[0]!=0){
      AA=(s[0]-'0')*10+(s[1]-'0');
      }else{
        AA=s[1]-'0';
        }

    if(s[2]!=0){
     BB=(s[2]-'0')*10+(s[3]-'0');
      }else{
        BB=s[3]-'0';
        }
    if(1<=AA && AA<=12 &&1<=BB && BB<=12) cout<<"AMBIGUOUS"<<endl;
    else if(1<=AA && AA<=12 && 0<=BB && BB<=99) cout<<"MMYY"<<endl;
    else if(0<=AA && AA<=99 && 1<=BB && BB<=12) cout<<"YYMM"<<endl;
    else cout<<"NA"<<endl;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int MOD = 1000000007;
const ll INF = 1LL << 60;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }

int main()
{
   int N,K;
   cin >> N >> K;
   vector<bool> appear(N + 1,true);
   vector<int> numCount (N + 1,0);
   vector<int> A(N);
   int kinds = 0;
   for(int i = 0; i < N; i++)
   {
       cin >> A[i];
       if(appear[A[i]])
       {
           kinds++;
           appear[A[i]] = false;
           numCount[A[i]]++;
       }
       else
       {
           numCount[A[i]]++;
       }
   }
//    cout << kinds << endl;
    // cout  << kinds - K << endl;
   if(kinds <= K)
   {
       cout << 0 << endl;
       return 0;
   }
   else
   {
       sort(numCount.begin(),numCount.end());
       int diff = 0;
       int diffKind = 0;
       for(int i = 0; i < N + 1; i++)
       {
           if(diffKind != kinds - K && numCount[i] != 0)
           {
                diffKind++;
                diff += numCount[i];
           }
           else if(diffKind == kinds - K)
           {
               cout << diff << endl;
               return (0);
           }
       }
   }
}
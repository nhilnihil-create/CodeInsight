#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
   ll N;
   cin >> N;
   vector<ll>A(N),B(N),C(N);
   for(int i = 0; i < N;i++) cin >> A[i];
   for(int i = 0; i < N;i++) cin >> B[i];
   for(int i = 0; i < N;i++) cin >> C[i];
   sort(A.begin(),A.end()),sort(B.begin(),B.end()),sort(C.begin(),C.end());
   ll ans = 0;
   for(auto x:B)
   {
       vector<ll>::iterator itr1 = lower_bound(A.begin(),A.end(),x);
       itr1--;
       if(*itr1 == 0) continue;
       vector<ll>::iterator itr2 = upper_bound(C.begin(),C.end(),x);
       if(itr2 == C.end()) continue;
       ans += (distance(A.begin(),itr1) + 1)*(N - distance(C.begin(),itr2));
   }
   cout << ans << endl;
}
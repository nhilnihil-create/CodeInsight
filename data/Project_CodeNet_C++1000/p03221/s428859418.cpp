#include <bits/stdc++.h>
using namespace std;

int main() {
   int N,M;
   cin >> N >> M;
   vector<tuple<int,int,int>> x(M);
   for (int i=0; i<M; i++) {
       int a,b;
       cin >> a >> b;
       x[i]=make_tuple(a,b,i);
   }
   sort(x.begin(),x.end());
   /*for (int i=0; i<M; i++) {
       cout << get<1>(x[i]) << endl;
       cout << get<2>(x[i]) << endl;
   }*/
   for (int i=0; i<M; i++) {
       if (i==0) {
           get<1>(x[0])=1;continue;
       }
       if (get<0>(x[i])==get<0>(x[i-1])) get<1>(x[i])=get<1>(x[i-1])+1;
       else get<1>(x[i])=1;
       //cout << i << " " << get<1>(x[i]) << endl;
   }
   vector<string> A(M);
   for (int i=0; i<M; i++) {
       string s=to_string(get<0>(x[i]));
       string t=to_string(get<1>(x[i]));
       int a,b;
       a=s.size();
       b=t.size();
       for (int j=0; j<6-a; j++) {
           s="0"+s;
       }
       for (int j=0; j<6-b; j++) {
           t="0"+t;
       }
       A[get<2>(x[i])]=s+t;
   }
   for (int i=0; i<M; i++) {
       cout << A[i] << endl;
   }
}
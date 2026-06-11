#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a,b,k;
   cin >> a >> b >> k;
   int rr = k,j=a;
   set <int> st;
   while(rr-- && j<=b)
   {
       st.insert(j);
       j++;
   }
    j = b;
    while(k-- && j>=a)
    st.insert(j--);

    for(auto itr = st.begin(); itr!=st.end(); ++itr)
    {
        cout << *itr << endl;
    }

}

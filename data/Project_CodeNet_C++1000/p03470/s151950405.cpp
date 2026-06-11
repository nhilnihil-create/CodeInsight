#include<bits/stdc++.h>
using namespace std;
#define For(start,end) for(int i = (int)start;i<(int)end;i++)
using Int = long long int;
int main(){
   int N;
   cin >> N;
   set<int>mochi;
   For(0,N)
   {
       int d;
       cin>>d;
       mochi.insert(d);
   }
    cout<<mochi.size()<<endl;


}
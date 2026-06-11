#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
int a,b;
cin>>a>>b;
int snow=0,bhigh=0;
for (int i = 1; i <= b-a; i++)
{
  bhigh+=i;
}

cout<<bhigh-b<<endl;


}

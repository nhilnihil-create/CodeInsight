#include<math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define    ll   long long int
#define    py   printf("Yes\n")
#define    pn   printf("No\n")
#define    in   cin>>
using namespace std;

int main()
{
  int x1,y1,x2,y2;
  in x1>>y1>>x2>>y2;
  int x=x2-x1;
  int y=y2-y1;
  cout<<x2-y<<" "<<y2+x<<" "<<x1-y<<" "<<y1+x<<endl;
}

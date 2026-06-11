#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
    speed_up;
    int n, cnt = 0, st = 0, mx, i, j, mx2;
    cin>>n;
    int a[n];
    int b[n] = {};
    for(i = 0; i<n; i++)
    {
        cin>>a[i];
    }
    mx = *max_element(a, a+n);
    
    j = 0;
   while(j<=mx)
   {st = 0;
    for(i = 0; i<n; i++)
    {
        if(b[i]<a[i])
        {
            b[i]++;
            if(st == 0)
            {
                cnt++;
                st = 1;
            }
        }
        else if(b[i]>=a[i]) st = 0;
    }
    j++;
  
   }

   cout<<cnt<<endl;




  return 0;
}


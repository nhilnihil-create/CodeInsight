#include <iostream>
#include <bitset>
using namespace std;
int n, a, s, i;
bitset<4000000> bs;
int main()
{
    bs[0] = 1;
    cin>>n;
    while(n--)
    {
        cin>>a;
        bs|=(bs<<a);
      //for(int j=0; j<bs.size(); j++)
     //{
     //     cout<<bs[j];
     //}
     //cout<<endl;
       s+=a;
    }
    for(i=(s+1)/2; !bs[i]; i++);
    cout<<i;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

#define MOD 1000000009
typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;



int main()
{

int arr[3];

for(int index = 0 ; index<  3 ; index++)
    cin>>arr[index];

sort(arr,arr+3);

if(arr[0]!=arr[1])
    cout<<arr[0]<<endl;
else
    cout<<arr[2]<<endl;


 return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
int N,x;scanf("%d %d",&N,&x);
vector<int> a(N);
for(int i=0;i<N;i++)scanf("%d ",&a[i]);
sort(a.begin(),a.end());
int nc=0;
while(x>=a[nc]&&nc<N){x-=a[nc];nc++;}
if(x>0&&nc==N)nc--;
printf("%d\n",nc);
}
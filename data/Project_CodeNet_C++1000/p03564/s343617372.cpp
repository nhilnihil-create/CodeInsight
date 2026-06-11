#include<bits/stdc++.h>
using namespace std;
int n,k;
int dp[100];
int y;int ans=INT_MAX;
void fun(int i,int y)
{
    if(i==n) {

        ans=min(ans,y);

        return ;
    }

    fun(i+1,2*y);
    fun(i+1,y+k);

}

int main()
{

cin>>n>>k;

fun(0,1);
cout<<ans<<endl;
    return 0;
}
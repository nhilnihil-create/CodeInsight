#include<bits/stdc++.h>
using namespace std ;

void solve()
{
    int m,n  ;
    cin>>m>>n ;

    vector<int> v(n) ;
    
    for(int i=0;i<n;i++){
        cin>>v[i] ;
    }

    sort(v.begin(),v.end()) ;

    priority_queue<int> q ;

    if(n>1){
        for(int i=1;i<n;i++)
        {

            int temp=v[i]-v[i-1] ;
            q.push(temp) ;
        }
    }

    int x=v[n-1]-v[0] ;

    if(n>1){
        for(int i=0;i<min(n-1,m-1);i++)
        {
            int t=q.top() ;
            x-=t ;
            q.pop() ;
        }
    }

    cout<<x  ;
}


int main()
{

    int y ;
    y=1 ;

    while(y--)
    {
        solve() ;
    }

}

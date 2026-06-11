#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
using namespace std;

long long int mod=1000000007;


long long int n,k,q,a[2300],b[5000],res,sum[2300]={},key=0;
queue<pair<long long ,long long > >que;
int main() {
    const long long int INF=99999999999999;
	map<long long int, long long int>mp;
    string str[550],red[550],blue[550];
    priority_queue<long long int,vector<long long int>,greater<long long int> >pq,tmp;

	cout << fixed << setprecision(10);
    cin>>n>>k>>q;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    for(int i=n;i<=4500;i++){
        b[i]=INF;
    }
    res=INF;
    long long int now=-1,need=0;
    for(int i=0;i<n;i++){
        need=0;
        now=-1;
        
        key=0;
        for(int j=0;j<n;j++){
            if(a[j]<b[i]){
                for(int i=now+1;i<j;i++){
                    tmp.push(a[i]);
                    
                
                }
                for(int i=1;i<=j-now-1-k+1;i++){
                    pq.push(tmp.top());
                    tmp.pop();
                
                }
                while(!tmp.empty()){
                    tmp.pop();
                }
                now=j;
                
            }
            
        }
        for(int i=now+1;i<n;i++){
            tmp.push(a[i]);
            
        
        }
        for(int i=1;i<=n-now-1-k+1;i++){
            pq.push(tmp.top());
            tmp.pop();
        
        }
        while(!tmp.empty()){
            tmp.pop();
        }

        if(pq.size()<q){break;}
        for(int i=0;i<q-1;i++){
            pq.pop();
        }
        res=min(res,pq.top()-b[i]);
        
        while(!pq.empty()){
            pq.pop();
        }
        //cout<<i<<" "<<res<<" "<<need<<endl;
        

    }
    
    cout<<res<<endl;
    
} 

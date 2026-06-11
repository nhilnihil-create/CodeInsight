#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <utility>
#include <iomanip>
#include <queue>

#define rep(i,n) for(int i=0;i< (n);++i)
typedef long long ll;

using namespace std;


int main(){
    int N;
    
    cin>>N;
    queue<int> q;
    vector<int> vec;
    int d[N+1];
    rep(i,N+1)d[i]=0;
    
    vec.push_back(1);
    for(int i=1;i<=6;++i){
        vec.push_back(pow(6,i));
    }
    for(int i=1;i<=5;++i){
        vec.push_back(pow(9,i));
    }
    

    /*
    for(int i=0;i!=vec.size();++i){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
     */
    
    int count=0;
    
    ++count;
    for(int i=0;i<vec.size();++i){
        int a=vec[i];
        if(a<=N){
           d[a]=count;
        }

        q.push(a);
    }
    
    
    
    while(!q.empty()){
        int b=q.front();
        //cout<<"b:"<<b<<endl;
        q.pop();
        //cout<<"count:"<<count<<endl;
        for(int j=0;j<vec.size();++j){
            int c=b+vec[j];
            if(c<=N){
                if(d[c]!=0)continue;
                d[c]=d[b]+1;
                q.push(c);
            }
        }
    }
    
    
    cout<<d[N]<<endl;
    
}

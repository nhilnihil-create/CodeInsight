#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,k,a;
    cin>>n>>k;
    std::deque<int> deq;
    for (int i=0;i<n;i++) {
        cin>>a;
        deq.emplace_back(a);
    }
    auto itr=find(deq.begin(),deq.end(),1);
    int dist=distance(deq.begin(),itr);
    int count=0,flag=0;
    if (n!=k) {
        //左側
        if (dist%(k-1)==0) {
            count+=dist/(k-1);
        } else {
            count+=dist/(k-1);
            count++;
            flag=1;
        }
        //cout<<count<<endl;
        //右側
        if (flag==1) {
            dist+=k-(dist%(k-1)+1);
            //cout<<dist<<endl;
        }
        if (n-(dist+1)>0) {
            if (n-(dist+1)>=k-1) {
                count+=(n-(dist+1))/(k-1);
                if ( (n-(dist+1))%(k-1)!=0 ) {
                    count++;
                }
            } else {
                count++;
            }
        }
        cout<<count<<endl;
    } else {
        cout<<1<<endl;
    }
}
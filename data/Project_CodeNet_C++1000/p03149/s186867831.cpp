#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    std::deque<int> deq(10,0);
    deq[a]=1;
    deq[b]=1;
    deq[c]=1;
    deq[d]=1;
    if (deq[1]==1&&deq[9]==1&&deq[7]==1&&deq[4]==1) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    queue<int> q;
    int ans=0;
    q.push(3);
    q.push(5);
    q.push(7);
    int tmp;
    int i,j,k;
    while(q.front()<=n){
            tmp=q.front();
            q.push(tmp*10+3);
            q.push(tmp*10+5);
            q.push(tmp*10+7);
            q.pop();
            i=0; j=0; k=0;
            while(tmp>0){
                if(tmp%10==3)i++;
                else if(tmp%10==5)j++;
                else if(tmp%10==7)k++;
                tmp/=10;
            }
            if(i>0&&j>0&&k>0)ans++;
    }
    cout << ans << endl;
}
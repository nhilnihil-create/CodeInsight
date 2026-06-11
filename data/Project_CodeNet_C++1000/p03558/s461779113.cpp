#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
    int K; cin>>K;
    vector<int> v(K, 1<<30);
    deque<int> q;
    q.push_back(1);
    v[1]=1;
    while (q.size()) {
        int p=q.front();
        q.pop_front();
        if (p==0) {
            cout<<v[p]<<endl;
            break;
        }
        if (v[p*10%K]>v[p]) {
            v[p*10%K]=v[p];
            q.push_front(p*10%K);
        }
        if (v[(p+1)%K]>v[p]+1) {
            v[(p+1)%K]=v[p]+1;
            q.push_back((p+1)%K);
        }
    }
}

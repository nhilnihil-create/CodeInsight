#include<iostream>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    int n,k;cin >> n >> k;
    vector<pair<int,int> > in(n);  
    for(int i=0;i<n;i++){
        int a,b;cin >> a >> b;
        a --;
        in[i] = make_pair(b,a);
    }
    sort(in.begin(),in.end());
    reverse(in.begin(),in.end());
    priority_queue<int> removable;
    set<int> used;
    long long sum = 0;
    for(int i=0;i<k;i++){
        int f = in[i].first;
        int s  =in[i].second;
        sum += f;
        if(used.count(s) > 0){
            removable.push(-f);
        }
        else{
            used.insert(s);
        }
    }
    long long tmp;
    long long x = used.size();
    long long ans = sum + x*x;
    tmp = ans;
    for(int i=k;i<n;i++){
        if(removable.empty()){
            break;
        }
        int f = in[i].first;
        int s = in[i].second;
        if(used.count(s) > 0){
            continue;
        }
        used.insert(s);
        x ++;
        long long diff = f + removable.top() + x*x - (x-1)*(x-1);
        removable.pop();

        tmp = tmp + diff;
        if(tmp > ans){
            ans = tmp;
        }
    }
    cout << ans << endl;
    return 0;
}
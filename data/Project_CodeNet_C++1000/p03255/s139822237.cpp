#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = unsigned long long;

ll n, x, xs[2*100000+5];

ll getCost(int k){
    ll result = 0;
    result += x*(n+k);
    result += (xs[0]-xs[k])*2;
    int i;
    for(i=0;i<n/k;i++){
        result += (2*i+3)*(xs[i*k]-xs[(i+1)*k]);
    }
    if(n%k!=0){
        result += (2*i+3)*(xs[i*k]-xs[n]);
    }
    return result;
}

int main(){
    int tmp;
    xs[0] = 0;

    cin >> n >> x;
    for(int i=0;i<n;i++){
        cin >> tmp;
        xs[i+1] = xs[i]+tmp;
    }
    reverse(begin(xs), begin(xs)+(n+1));

    ll ans = getCost(1);
    for(int i=2;i<=n;i++)
        ans = min(ans, getCost(i));

    cout << ans << endl;

/*
    int p[4];
    ll q[4];
    p[0] = 1;
    q[0] = getCost(p[0]);
    p[3] = n;
    q[3] = getCost(p[3]);
    while(p[3]-p[0]>3){
        //cout << p[0] << " " << p[3] << endl;
        p[1] = (p[0]+p[3])/2;
        q[1] = getCost(p[1]);
        p[2] = p[1]+1;
        q[2] = getCost(p[2]);
        ll m = *min_element(begin(q), end(q));
        if(m==q[0]){
            p[3] = p[1];
            q[3] = q[1];
        }
        else if(m==q[3]){
            p[0] = p[2];
            q[0] = q[2];
        }
        else if(m==q[1]){
            q[0] = q[1];
            p[0] = p[1];
        }
        else{
            q[3] = q[2];
            p[3] = p[2];
        }
    }
    p[1] = (p[0]+p[3])/2;
    q[1] = getCost(p[1]);
    p[2] = p[1]+1;
    q[2] = getCost(p[2]);

    cout << (*min_element(begin(q), end(q))) << endl;
*/

/*
    下凸っぽいので最小値を探索できそう?
    for(int k=1;k<=n;k++)
        cout << k << "回目： " << getCost(k) << endl;
*/

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

using i64 = long long int;

i64 bsearch(vector<i64> &v, i64 t){
    if(t <= v[0])return 0;
    i64 left = 0, right = v.size();
    while(abs(right-left) > 1){
        i64 mid = (right + left) / 2;
        if(v[mid] < t)left = mid;
        else right = mid;
    }
    return right;
}

i64 count(vector<i64> &v, i64 lower, i64 upper){
    i64 left_index = bsearch(v, lower);
    i64 right_index = bsearch(v, upper);
    return right_index - left_index;
}

int main(){
    i64 n;
    cin >> n;
    vector<i64> a, b;
    for(i64 i=0;i<n;++i){
        i64 tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    for(i64 i=0;i<n;++i){
        i64 tmp;
        cin >> tmp;
        b.push_back(tmp);
    }

    i64 ans = 0;
    for(i64 k=0;k<30;++k){
        vector<i64> a_mod = a, b_mod = b;
        for(i64 i=0;i<n;++i){
            a_mod[i] %= (1<<(k+1));
            b_mod[i] %= (1<<(k+1));
        }

        sort(b_mod.begin(), b_mod.end());

        i64 cnt = 0, t = (1 << k);
        for(i64 i=0;i<n;++i){
            cnt += count(b_mod, t-a_mod[i], 2*t-a_mod[i]) + count(b_mod, 3*t-a_mod[i], 4*t-a_mod[i]);
        }
        ans |= ((cnt%2) << k);
    }

    cout << ans << endl;

    return 0;
}

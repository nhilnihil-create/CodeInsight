#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



int main(){

    int n,m;

    cin >> n >> m;



    vector<vector<int>> s(m);



    for(int i = 0; i < m; i++){

        int k;

        cin >> k;

        for(int j = 0; j < k; j++){

            int sw;

            cin >> sw;

            sw--;

            s[i].push_back(sw);

        }

    }



    vector<int> p(m);

    for(int i = 0; i < m; i++)

        cin >> p[i];

    

    ll ans = 0;

    for(int bit = 0; bit < (1 << n); bit++){

        bool flag = true;

        for(int i = 0; i < m; i++){

            int cnt = 0;

            for(auto v : s[i]){

                if(bit & (1 << v))

                    cnt++;

            } 

            if(cnt % 2 != p[i])

                flag = false;

        }

        if(flag)

            ans++;

    }



    cout << ans << endl;



    return 0;

}
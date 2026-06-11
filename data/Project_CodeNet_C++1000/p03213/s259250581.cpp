#include<bits/stdc++.h>

using namespace std;
using ll = long long;

map<int,int> Map;
template<class T>
void fact(T n){
    for(T i = 2; i * i <= n; i++){
        while(n % i == 0){
            Map[i]++;
            n /= i;
        }
    }
    if(n == 1)return;
    Map[n]++;
}


int main()
{
    int n;
    cin >> n;
    if(n < 10) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++) fact(i);
    int res = 0;
    vector<int> num;
    for(auto i : Map)num.push_back(i.second);
    int m = num.size();

    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            for(int k = 0; k < m; k++) {
                if(i == k || j == k)continue;
                if(num[i] >= 4 && num[j] >= 4 && num[k] >= 2)res++;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(i == j)continue;
            if(num[i] >= 14 && num[j] >= 4)res++;
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(i == j)continue;
            if(num[i] >= 24 && num[j] >= 2)res++;
        }
    }
    if(num.front() >= 74)res++;
    
    
    cout << res << endl;
}
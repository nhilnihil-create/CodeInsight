#include<bits/stdc++.h>
using ll = long long;
const ll INF = 1000000000000;
#define fir first
#define sec second

class Union_Find{
private:
    std::vector<long long> data; //data[i] : 頂点iの親
public:
    Union_Find(int n){
        data.resize(n,-1);
    }
    //頂点iの親を返す
    int root(int i){
        if(data[i] < 0)return i;
        else return data[i] = root(data[i]);
    }
    //連結
    void unit(int i,int j){
        i = root(i);j = root(j);
        if(i != j){
            data[i] += data[j];
            data[j] = i;
        }
    }

    //頂点iの属する集合の頂点数
    int size(int i){
        i = root(i);
        return data[i];
    }
};

int main()
{
    int n,m;
    std::cin >> n >> m;
    std::vector<int> p(n);
    for(int i = 0; i < n; i++){std::cin >> p[i];p[i]--;}
    Union_Find uni(n);
    for(int i = 0; i < m; i++){
        int t,k; std::cin >> t >> k;
        t--;
        k--;
        uni.unit(t,k);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(uni.root(p[i]) == uni.root(i))cnt++;
    }
    std::cout << cnt << std::endl;
}

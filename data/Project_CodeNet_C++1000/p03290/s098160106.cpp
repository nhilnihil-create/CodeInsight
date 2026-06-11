#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i, n) for(int i=0;i<(int)n;++i)
using P = pair<int, int>;
const int INF = 1001001001;

int binary_brute_force(const vector<P> &vec, int G)
{
    int n = vec.size(), ans = INF, num_p, point;
    for(int i=0;i<(1 << n);++i)
    {
        num_p = 0;
        point = 0;
        for(int j=0;j<n;++j)
        {
            if((i >> j) & 1)
            {
                num_p += vec[j].first;
                point += vec[j].first * 100 * (n-j) + vec[j].second;
            }
        }

        for(int j=0;j<n;++j)
        {
            if(G <= point) break;
            if(!((i >> j) & 1))
            {
                if(G <= point + (vec[j].first-1) * 100 * (n-j)){
                    num_p += (G - point - 1) / (100 * (n-j)) + 1;
                    ans = min(ans, num_p);
                    break;
                }
                else{
                    num_p += vec[j].first - 1;
                    point += (vec[j].first-1) * 100 * (n-j);
                }
            }
        }
        if(G <= point) ans = min(ans, num_p);
    }
    return ans;
}

int dfs(const vector<P> &vec, int G, int point, int num, int index, int state)
{
    int ans;
    int n = vec.size();
    if(G <= point){
        return num;
    }
    if(index >= vec.size())
    {
        for(int i=0;i<n;++i)
        {
            if(!((state >> i) & 1))
            {
                if(G <= point + (vec[i].first - 1)*100*(n-i))
                {
                    num += (G - point - 1) / (100*(n-i)) + 1;
                    return num;
                }
                else{
                    num += vec[i].first - 1;
                    point += (vec[i].first - 1)*100*(n-i);
                }
            }
        }
        if(G > point) return INF;
        else return num;
    }
    // indexの問題を全部解く
    ans = dfs(vec, G, point+vec[index].first*100*(n-index)+vec[index].second, num+vec[index].first, index+1, state + (1 << index));
    // 解かない
    ans = min(ans, dfs(vec, G, point, num, index+1, state));
    return ans;
}

int main()
{
    int D, G;
    cin >> D >> G;
    vector<P> vec(D);
    rep(i, D) cin >> vec[i].first >> vec[i].second;
    reverse(vec.begin(), vec.end());
    //cout << binary_brute_force(vec, G) << endl;
    cout << dfs(vec, G, 0, 0, 0, 0) << endl;
}

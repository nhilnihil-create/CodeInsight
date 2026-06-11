#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i, n) for(int i=0;i<(int)n;++i)
using P = pair<int, int>;
const int INF = 1001001001;

int binary_brute_force(const vector<P>& vec, int G)
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
                if(G <= point + vec[j].first * 100 * (n-j)){
                    num_p += (G - point - 1) / (100 * (n-j)) + 1;
                    break;
                }
                else{
                    num_p += vec[j].first;
                    point += vec[j].first * 100 * (n-j);
                }
            }
        }
        ans = min(ans, num_p);
    }
    return ans;
}


int main()
{
    int D, G;
    cin >> D >> G;
    vector<P> vec(D);
    rep(i, D) cin >> vec[i].first >> vec[i].second;
    reverse(vec.begin(), vec.end());
    cout << binary_brute_force(vec, G) << endl;
}

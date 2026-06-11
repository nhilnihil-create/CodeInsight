#include <bits/stdc++.h>
using namespace std;

#define  ll    long long int

int cnt[111];
set<int> prime;
set<int>::iterator it;

void go(int n)
{
    int i, j, rt = sqrt(n);
    for (i = 2; i <= rt; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
                cnt[i]++;
            }
            prime.insert(i);
        }
    }
    if (n != 1) {
        prime.insert(n);
        cnt[n]++;
    }
}

int main( )
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        go(i);
    }
    int i, j, k;
    vector<int> v;
    for (it = prime.begin(); it != prime.end(); it++) {
        //cout << (*it) << ' ' << cnt[(*it)] << '\n';
        v.push_back(*it);
    }
    int c = 0;
    set< pair<int, pair<int, int> > > st1;
    for (i = 0; i < (int) v.size(); i++) {
        if (cnt[v[i]] >= 74) c++;
        for (j = 0; j < (int) v.size(); j++) {
            if (i == j) continue;
            if (cnt[v[i]] >= 2 && cnt[v[j]] >= 24) c++;
            if (cnt[v[i]] >= 4 && cnt[v[j]] >= 14) c++;
            for (k = 0; k < (int) v.size(); k++) {
                if (i == k || j == k)  continue;
                if (cnt[v[i]] >= 2 && cnt[v[j]] >= 4 && cnt[v[k]] >= 4) {
                    int a = v[j];
                    int b = v[k];
                    if (a < b) swap(a, b);
                    st1.insert(make_pair(v[i], make_pair(a, b)));
                }
            }
        }
    }
    cout << c + (int) st1.size() << '\n';
    return 0;
}
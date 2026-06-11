#include<algorithm>
#include<cstdio>
#include<map>
#include<queue>
#include<vector>
using namespace std;

int n, k;
map<int, vector<int>> m;
vector<vector<int>*> v;
priority_queue<int> p;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int t, d;
        scanf("%d %d", &t, &d);
        m[t].push_back(d);
    }
    for (map<int, vector<int>>::iterator i = m.begin(), e = m.end();
         i != e; i++) {
        sort(i->second.begin(), i->second.end());
        v.push_back(&i->second);
    }
    sort(v.begin(), v.end(), [](const vector<int> *v1, const vector<int> *v2)->bool {
        return v1->back() > v2->back();
    });
    int vs = (k <= v.size()) ? k : v.size();
    int ans[k];
    for (int i = 0; i < vs; i++) {
        ans[i] = v[i]->back();
        v[i]->pop_back();
    }
    for (int i = 0; i < vs; i++) {
        for (vector<int>::iterator j = v[i]->begin(), e = v[i]->end(); j != e; j++) {
            p.emplace(*j);
        }
    }
    for (int i = vs; i < k; i++) {
        ans[i] = p.top();
        p.pop();
    }
    int x = vs;
    while(true) {
        if (p.empty() || ans[x - 1] + 2 * x - 1 >= p.top()) break;
        ans[--x] = p.top();
        p.pop();
    }
    long sum = 0;
    for (int i = 0; i < k; i++) sum += ans[i];
    sum += static_cast<long>(x) * x;
    printf("%ld\n", sum);
    return 0;
}

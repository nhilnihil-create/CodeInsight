#include <bits/stdc++.h>
using namespace std;

int main() {
    int D, G;
    cin >> D >> G;
  
    vector<int> p(D);
    vector<int> c(D);
    for (int i = 0; i < D; i++) {
        cin >> p.at(i) >> c.at(i);
    }
  
    bitset<10> b;
    int score, p_num, min_p_num = 1000;
    for (int tmp = 0; tmp < (1 << D); tmp++) {
        b = tmp;
        score = 0;
        p_num = 0;
        for (int i = 0; i < D; i++) {
            if (b.test(i)) {
                score += 100 * (i + 1) * p.at(i) + c.at(i);
                p_num += p.at(i);
            }
        }
        if (p_num >= min_p_num) {
            continue;
        }
        if (score > G) {
            min_p_num = p_num;
            continue;
        }

        int highest = D - 1;
        while (b.test(highest)) highest--;
        
        int add = 100 * (highest + 1) * (p.at(highest) - 1);
        if (score + add < G) {
            continue;
        }

      	while (score < G) {
          score += 100 * (highest + 1);
          p_num++;
        }
        min_p_num = min(min_p_num, p_num);
    }
    cout << min_p_num << endl;
}

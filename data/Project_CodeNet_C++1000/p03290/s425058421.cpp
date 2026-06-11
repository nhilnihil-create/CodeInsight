#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
    int D, G;
    cin >> D >> G;
    vector<int> p(D), c(D);
    for (int i = 0; i < D; i++) {
        cin >> p[i] >> c[i];
    }
    int min_problems = 100 * D;
    //cout << "G = " << G << endl << endl;

    for (int s = 0; s < (1 << (D)); s++) {
        //cout << "case : s = " << s << endl;
        int problems = 0, points = 0;
        vector<int> p_temp(D);
        for (int i = 0; i < D; i++) {
            p_temp[i] = p[i];
        }

        for (int t = 0; t < D; t++) { //ボーナス込みで問題を解く
            if (s & (1 << t)) {
               problems += p_temp[t];
                int point = 100 * (t + 1) * p_temp[t];
                point += c[t];
                points += point;
                p_temp[t] = 0;
            }
        }
        //cout << "   current points = " << points << endl;

        for (int t = p_temp.size() - 1; points < G; t--) { //点数の高い問題から順に
            if (p_temp[t] == 0) {
                continue;
            }
            while (p_temp[t] > 0 && points < G) {
                points += 100 * (t + 1);
                p_temp[t]--;
                problems++;
            }
            if (p_temp[t] == 0) {
                points += c[t];
            }
        }
        /*cout << "   last points = " << points << endl;

        cout << "   problems = " << problems << ", ";
        if (problems > min_problems) {
            cout << "min_problems < problems";
        } else {
            cout << "problems < min_problems";
        }
        cout << endl;*/

        min_problems = min(problems, min_problems);
    }

    cout << min_problems << endl;

    return 0;
}
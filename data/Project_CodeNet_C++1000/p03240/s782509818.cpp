#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;    using std::cin;
using std::endl;    using std::vector;
using std::max;     using std::abs;

int main() {

    int n;
    cin >> n;

    vector<int> vx, vy, vh;
    for (int i = 0; i != n; ++i) {

        int x, y, h;
        cin >> x >> y >> h;

        vx.push_back(x);
        vy.push_back(y);
        vh.push_back(h);
    }

    typedef vector<int>::size_type size;

    size count = 0;

    while (vh[count] == 0)
        ++count;

    for (size i = 0; i != 101; ++i) {

        for (size j = 0; j != 101; ++j) {

            int H, Cx = i, Cy = j;
            H = vh[count] + abs(vx[count] - Cx) + abs(vy[count] - Cy);

            size k = 0;
            while (k != n) {

                if (vh[k] != max(H - abs(vx[k] - Cx) - abs(vy[k] - Cy), 0))
                    break;

                ++k;
            }

            if (k == n) {

                cout << Cx << " " << Cy << " " << H << endl;

                return 0;
            }
        }
    }

}

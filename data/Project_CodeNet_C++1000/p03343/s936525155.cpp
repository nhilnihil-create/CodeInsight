#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k ,q;
    cin >> n >> k >> q;
    int *a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int *sorted = new int[n];
    for (int i = 0; i < n ;i++) sorted[i] = a[i];
    sort(sorted, sorted + n);

    int res = 1000000000;
    int min = 0;
    int *b = new int[n];
    int *c = new int[n];
    for (int i = 0; i <= n - q - k + 1; i++) {
        if (min < sorted[i]) min = sorted[i];
        else continue;

        //cout << min << endl;

        int ran_sum = 0;
        int ran = 0;
        int start_pos = 0;
        int bi = 0;
        int rmvbl = 0;
        int rmvbl_sum = 0;
        for (int j = 0; j <= n; j++) {
            if (j < n && a[j] >= min) ran++;
            else {
                if (ran < k) {
                    ran = 0;
                    start_pos = j+1;
                    continue;
                }
                rmvbl = ran - k + 1;
                rmvbl_sum += rmvbl;
                ran_sum += ran;

                int ci = 0;
                for (int x = start_pos; x < j; x++) {
                    c[ci] = a[x];
                    ci++;
                }
                sort (c, c + ran);
                for (int x = 0; x < rmvbl; x++) {
                    b[bi] = c[x];
                    bi++;
                }

                ran = 0;
                start_pos = j+1;
            }
        }

        //cout << rmvbl_sum << endl;
        //cout << bi << endl;

        if (rmvbl_sum < q) break;

        sort(b, b + rmvbl_sum);
        //for (int j = 0; j < rmvbl_sum; j++) cout << b[i] << " ";
        //cout << endl;
        if (b[q-1] - min < res) res = b[q-1] - min;
        //cout << res << endl;
        //cout << endl;
    }

    cout << res << endl;

    return 0;
}
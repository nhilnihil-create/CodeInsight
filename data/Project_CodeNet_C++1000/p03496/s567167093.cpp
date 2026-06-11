#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; i++) {
        cin >> a[i];
    }

    cout << 2*(N-1) << endl;
    int a_min = *min_element(a.begin(), a.end());
    int a_max = *max_element(a.begin(), a.end());
    if(abs(a_min) <= abs(a_max)) {
        int max_pos = distance(a.begin(), max_element(a.begin(), a.end()));
        for(int i=0; i<N; i++) {
            if(i != max_pos) {
                cout << max_pos+1 << " " << i+1 << endl;;
            }
        }
        for(int i=1; i<N; i++) {
            cout << i << " " << i+1 << endl;
        }
    } else {
        int min_pos = distance(a.begin(), min_element(a.begin(), a.end()));
        for(int i=0; i<N; i++) {
            if(i != min_pos) {
                cout << min_pos+1 << " " << i+1 << endl;;
            }
        }
        for(int i=N; i>1; i--) {
            cout << i << " " << i-1 << endl;
        }
    }
    return 0;
}

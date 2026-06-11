#include <iostream>
using namespace std;
class restaulant {
    public:
        string city;
        int point;
        int id;
};
int main() {
    int n;
    cin >> n;
    restaulant r[n];
    for (int i=0; i<n; i++) {
        string s;
        int p;
        cin >> s >> p;
        r[i].city = s;
        r[i].point = p;
        r[i].id = i+1;
    }
    for (int i=1; i<n; i++) {
        restaulant tmpr =r[i];
        int j = i-1;
        while (j>=0 && (r[j].city>tmpr.city || ((r[j].city==tmpr.city) && (r[j].point<tmpr.point)))) {
            r[j+1] = r[j];
            j--;
        }
        r[j+1] = tmpr;
    }
    for (int i=0; i<n; i++) {
        cout << r[i].id << endl;
    }
}
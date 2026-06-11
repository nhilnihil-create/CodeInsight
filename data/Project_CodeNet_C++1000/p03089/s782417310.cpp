#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {

    int n;

    cin >> n;

    vector<int> v(n);
    list<int> l;

    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        l.push_front(num);
    }

    vector<int> ans;
    for(int i = 0; i < n; ++i) {
        /*
        for(auto itr = l.begin(); itr != l.end(); itr++)
            cout << *itr << " ";
        cout << endl;
        */
        int count = l.size();
        for(auto itr = l.begin(); itr != l.end(); itr++) {
            if(count == *itr) {
                ans.push_back(count);
                l.erase(itr);
                break;
            }
            count--;
        }

    }


    if(ans.size() == n) {
        for(int i = n - 1; i >= 0; --i)
            cout << ans[i] << endl;

    }
    else {
        cout << -1 << endl;
    }

    return 0;

}
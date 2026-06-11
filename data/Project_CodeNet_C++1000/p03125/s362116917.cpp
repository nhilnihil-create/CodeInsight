#include <iostream>
#include <vector>
using namespace std;

bool search_x(int x, vector<int> p){
    for (int i = 0; i < p.size(); i++) {
        if (x == p.at(i))
            return true;
    }
    return false;
}

int main()
{
    int a, b, ans;
    cin >> a >> b;
    ans = (b % a == 0) ? a + b : b - a;
    cout << ans << endl;
}
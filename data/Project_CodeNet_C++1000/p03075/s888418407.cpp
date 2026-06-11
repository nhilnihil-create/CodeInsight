#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int a, b, c, d, e, k;
    cin >> a >> b >> c
    	>> d >> e >> k;
    int v[5] = {a, b, c, d, e};
    cout << ((*max_element(v , v + 5) - *min_element(v, v+5)) <= k ? "Yay!" : ":(") << endl; 
}
#include <iostream>
#include <iostream>
using namespace std;

int n, m, x, a, first=0, last=0;

int main(){
    cin >> n >> m >> x;
    for(int i=0; i<m; i++){
        cin >> a;
        a<x? first++:last++;
    }
    cout << min(first, last) << endl;
}

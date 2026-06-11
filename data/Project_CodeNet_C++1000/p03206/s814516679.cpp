#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string xmaseve (string xmas, int n) {
    if (n==25)
        return xmas;
    else if (n<25) {
        return (xmaseve(xmas, n+1) + " Eve");
    }
}

int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL); cout.tie(NULL);

    int n;

    cin >> n;

    cout << xmaseve("Christmas", n);

}

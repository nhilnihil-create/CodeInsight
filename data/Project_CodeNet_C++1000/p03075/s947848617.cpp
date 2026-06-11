#include <bits/stdc++.h>
using namespace std;


#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vi antenas(5);
    int dist;

    for ( int i = 0; i < 5; i++ ) cin >> antenas[i];
    cin >> dist;

	for ( int i = 0; i < 4; i++ ) {
		for ( int j = i + 1; j < 5; j++ ) {
			if ( abs(antenas[i] - antenas[j]) > dist ) {
				cout << ":(\n";
				return 0;
			}
		}
	}

	cout << "Yay!\n";


    return 0;
}

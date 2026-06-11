#include <bits/stdc++.h>
using namespace std;

int main() {
	double rating_from,rating_to;
    int performance;
    cin >> rating_from >> rating_to;
    performance = rating_to * 2 - rating_from;
    cout << performance << endl; 
}
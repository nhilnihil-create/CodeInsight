#include <bits/stdc++.h>
using namespace std;

int main() {
	int currentRating, nextRating, nextRatingBy;
  	cin >> currentRating >> nextRatingBy;
  	nextRating = nextRatingBy*2 - currentRating;
  	cout << nextRating << endl;
}
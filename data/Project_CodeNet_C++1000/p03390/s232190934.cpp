#include <bits/stdc++.h>
using namespace std;

/*Q5.
Chocolate brands were ranked according to which had the best taste. There were 10^30 chocolate brands in total.
Two judges ranked the chocolates in the increasing order of taste. The ranks given are unique (1 to 10^30 by each judge). 
The final score is the product of the scores given by the two judges. You have to process Q queries. 
Our chocolate of interest had ranks Xi and Yi given by the two judges. 
You have to determine the maximum number of participants whose score is less than the score of our brand in each case.

Constraints:
1 <= Q <= 100
1 <= Xi,Yi <= 10^9 (1<= i <= Q)

Input:
First line contains Q
Next Q lines contain Xi and Yi

Output: 
Maximum number of brands having a score less than our brand. 
https://arc094.contest.atcoder.jp/tasks/arc094_b */

typedef long long ll;
typedef long double ld;

int main()
{
	ll a,b,q;
	cin >> q;
	while(q--)
	{
		cin >> a >> b;
		if(a>b) swap(a,b);
		if(a==b) cout << (2*a-2) << '\n';
		else if(a+1==b) cout << (2*a-2) << '\n';
		else
		{
			ld c = sqrt((ld)a*(ld)b);
			ll c1=c;
			if(c1==c) c1--;
			if((c1*(c1+1))>=(a*b)) cout << (2*c1-2) << '\n';
			else cout << (2*c1-1) << '\n';

		}
	}
	return 0;
}
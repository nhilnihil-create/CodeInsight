#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

int		main(void)
{
	string S, T;
	cin >> S >> T;

	reverse(all(S));
	reverse(all(T));
	for (int i = 0; i < (int)S.size(); ++i)
	{
		int j = 0;
		while (j < (int)T.size() && (S[i+j] == '?' || S[i+j] == T[j]))
			++j;
		if (j == (int)T.size())
		{
			--j;
			for (int k = (int)S.size()-1; k >= 0; --k)
			{	
				if (i <= k && k <= i+j)
					cout << T[j--];
				else if (S[k] == '?')
					cout << 'a';
				else
					cout << S[k];
			}
			cout << endl;
			return 0;
		}
	}
	cout << "UNRESTORABLE" << endl;
}


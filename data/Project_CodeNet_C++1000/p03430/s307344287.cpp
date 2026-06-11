#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int kq,k,result[330][330][330];
string s;
int main()
{
		cin >> s;
		int cd = s.size();
		cin >> k;
		s = '0' + s;
		for (int e = 1 ; e <= cd ; e++)
		{
				for (int i = 1 ; i <= cd ; i++)
				{
						if (i + e - 1 > cd) 
						{
								break;
						}
						for (int f = 0 ; f <= min(k,e) ; f++)
						{
								int cur = i;
								int nxt = i + e - 1;
								if (f == e)
								{
										result[i][e][f] = e;
								}
								else
								{
										if (e == 2)
										{
												if (s[i] == s[i+1])
												{
														result[i][e][0] = 2;
												}
												else
												{
														result[i][e][0] = 1;
												}
												result[i][e][1] = 2;
												result[i][e][2] = 2;
										}
										else
										{
												if (e - 1 > 0)
												{
														result[i][e][f] = max(result[i][e][f] , result[i][e-1][f]);
												}
												if (i + 1 <= cd)
												{
														result[i][e][f] = max(result[i][e][f] , result[i+1][e-1][f]);
												}
												if (f != 0 && e - 2 > 0 && i + 1 <= cd)
												{
														result[i][e][f] = max(result[i][e][f] , result[i+1][e-2][f-1] + 2);
												}
												if (e - 2 >= 1)
												{
														result[i][e][f] = max(result[i][e][f] , result[i+1][e-2][f]);
												}
												if (s[cur] == s[nxt] && e - 2 > 0 && i + 1 <= cd)
												{
														result[i][e][f] = max(result[i][e][f] , result[i+1][e-2][f] + 2);
												}
										}
								}
								if (e == 1)
								{
										result[i][e][f] = 1;
								}
								kq = max(kq , result[i][e][f]);
						}
				}
		}
		cout << kq;
}

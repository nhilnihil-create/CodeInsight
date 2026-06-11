#include <iostream>
#include <math.h>
#include <string>
using namespace std;


int main()
{
	int N;
	int ta = 0, xa = 0, ya = 0, tb, xb, yb; //a:before b:after
	string s = "Yes"; //何もなければそのまま出力
	cin >> N;


	for (int i = 0; i < N; i++) {
		cin >> tb >> xb >> yb;

		if (tb % 2 != (xb + yb) % 2) { //そもそも到達し得ない
			s = "No";
			break;
		}
		else if (tb-ta < (abs(xb-xa)+abs(yb-ya))) { //マンハッタン距離が時間より短いと間に合わない
			s = "No";
			break;
		}
		ta = tb;
		xa = xb;
		ya = yb;
	}
	cout << s << endl;
	return 0;
}
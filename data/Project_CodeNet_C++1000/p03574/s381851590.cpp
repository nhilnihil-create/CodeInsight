#include <iostream>
using namespace std;

int main() {

	int h, w;

	cin >> h >> w;

	string all;

	for (int i = 0; i < h; i++) {

		string str;

		cin >> str;

		all += str;
	}

	for (int i = 0; i < all.size(); i++) {

		if (all.at(i) == '#') {

			cout << "#";

		}
		else {

			int leftUp = i - (w + 1);
			int up = i - w;
			int rightUp = i - (w - 1);

			int left = i - 1;
			int right = i + 1;

			int leftBottom = i + (w - 1);
			int bottom = i + w;
			int rightBottom = i + (w + 1);



			int how = 0;

			if (left % w != w -1 && left >= 0) {

				if (all.at(left) == '#') {

					how++;

				}

				if (leftUp >= 0 && all.at(leftUp) == '#') {


					how++;

				}

				if (leftBottom < h * w && all.at(leftBottom) == '#') {

					how++;

				}

			}

			if (right % w != 0 && right < h * w) {

				if (all.at(right) == '#') {

					how++;

				}

				if (rightUp >= 0 && all.at(rightUp) == '#') {

					how++;

				}

				if (rightBottom < h * w && all.at(rightBottom) == '#') {

					how++;

				}

			}

			if (up >= 0 && all.at(up) == '#') {

				how++;

			}

			if (bottom < h * w && all.at(bottom) == '#') {

				how++;

			}

			cout << how;

		}

		if ((i + 1) % w == 0) {

			cout << endl;

		}



	}



}

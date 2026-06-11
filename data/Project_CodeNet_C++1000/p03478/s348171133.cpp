#include <stdio.h>

int main () {
	int ans = 0;
	int N, A, B;
	scanf ("%d %d %d", &N, &A, &B);
	for (int i = 0; i <= N; i++) {
		int digit = 0;
		int aa = i;
		while (aa != 0) {
			digit = digit + aa % 10;
			aa /= 10;
		}
		
		if (digit >= A && digit <= B) {
			ans += i;
		}
//		if (i == 10 || i == 100 || i == 1000 || i == 10000) {
//			if (1 >= A && 1 <= B) {
//				ans += i;	
//			}
//		} else if (i < 10) {
//			if (i >= A && i <= B) {
//				ans += i;
//				}
//		} else if (i > 10 && i < 100) {
//			int Bb = i / 10;
//			int Bbb = i - (Bb*10);
//			int B1 = Bb + Bbb;
//			if (B1 >= A && B1 <= B) {
//				ans += i;
//			}	
//		} else if (i > 100 && i < 1000) {
//			int Cc = i / 100;
//			int Ccc = (i - (Cc*100)) / 10;
//			int Cccc = i - (Cc * 100) - (Ccc * 10);
//			int C1 = Cc + Ccc + Cccc;
//			if (C1 >= A && C1 <= B) {
//				ans += i;
//			}	
//		} else if (i > 1000 && i < 10000) {
//			int D = i / 1000;
//			int Dd = (i - (D*100)) / 100;
//			int Ddd = (i - (D * 1000) - (Dd * 100) / 10);
//			int Dddd = i - (D * 1000) - (Dd * 100) - (Ddd * 10);
//			int D1 = D + Dd + Ddd + Dddd;
//			if (D1 >= A && D1 <= B) {
//				ans += i;
//			}
//		}
	}
	printf ("%d", ans);
	return 0;
}
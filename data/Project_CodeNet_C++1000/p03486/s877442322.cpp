#include<iostream>
#include<string.h>
using namespace std;

void ss(string *s) {
	for (int i = 0; i < s->size(); i++) {
		int min = s->at(i);
		int ii = i;
		for (int k = i; k < s->size(); k++) {

			if (min > s->at(k)) {
				min = s->at(k);
				ii = k;
			}
		}
		int swap = s->at(i);
		s->at(i) = min;
		s->at(ii) = swap;
	}
}
void tt(string* t) {
	for (int i = 0; i < t->size(); i++) {
		int min = t->at(i);
		int ii = i;
		for (int k = i; k < t->size(); k++) {

			if (min < t->at(k)) {
				min = t->at(k);
				ii = k;
			}
		}
		int swap = t->at(i);
		t->at(i) = min;
		t->at(ii) = swap;
	}
}
int main() {
	string s, t;
	cin >> s >> t;
	int ln, lm;
	ln = s.size();
	lm = t.size();

	ss(&s);
	tt(&t);
	/*int i = 0;
	while (i<ln&&i<lm&&s.at(i) == t.at(i)) {
		i++;
	}
	if (i==ln) {
		if (ln < lm)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else {
		if (s.at(i) < t.at(i))cout << "Yes" << endl;
		else cout << "No" << endl;
	}*/
	if (s < t)cout << "Yes" << endl;
	else cout << "No" << endl;

	

}
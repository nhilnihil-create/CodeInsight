#include <iostream>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int cats, cat_dog, num_cat;

	cin >> cats >> cat_dog >> num_cat;

	if(num_cat < cats || num_cat > (cats + cat_dog)) {
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
	}

	return 0;
}